package com.example.androidproject;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.ActionBarDrawerToggle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.Volley;
import com.google.android.material.navigation.NavigationView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    TextView tvFLName, tvPhoneNumber;
    //RecyclerView recyclerView;
    RequestQueue requestQueue;
    View view;
    Toolbar toolbar;
    ActionBar actionBar;
    DrawerLayout drawerLayout;
    ActionBarDrawerToggle drawerToggle;
    NavigationView navigationView;
    //RecyclerView.Adapter adapter;
    ListView list;

    Person temp;
    //List<Person> persons;
    ArrayList<Person> arrayList;

    SharedPreferences sharedpreferences;
    public final String Url = "http://116.202.20.190:9000/jason/contacts/";
    String FLName, PhoneNumber;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        actionBar.setHomeButtonEnabled(true);

        drawerLayout = findViewById(R.id.drawer_layout);
        drawerToggle = new ActionBarDrawerToggle(this, drawerLayout, toolbar, 0, 0);
        drawerToggle.syncState();

        navigationView = findViewById(R.id.navigation_view);

        view = navigationView.getHeaderView(0);
        tvFLName = view.findViewById(R.id.tv_fl_name_header);
        tvPhoneNumber = view.findViewById(R.id.tv_phone_number_header);

        navigationView.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.nav_home:
                        Toast.makeText(MainActivity.this, "Camera", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_gallery:
                        Toast.makeText(MainActivity.this, "Gallery", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_slideshow:
                        Toast.makeText(MainActivity.this, "SlideShow", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_tools:
                        Toast.makeText(MainActivity.this, "Tools", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_exit:
                        finishAffinity();
                        break;
                    case R.id.nav_sign_out:
                        SharedPreferences sharedpreferences = getSharedPreferences("key_MyPREFERENCES", Context.MODE_PRIVATE);
                        SharedPreferences.Editor editor = sharedpreferences.edit();
                        editor.clear();
                        editor.commit();
                        Intent intent = new Intent(MainActivity.this, RegisterActivity.class);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                        startActivity(intent);
                        finish();
                        break;
                }
                return true;
            }
        });


        requestQueue = Volley.newRequestQueue(this);
        /*
        recyclerView = findViewById(R.id.recycleViewContainer);

        persons = new ArrayList<>();
        recyclerView.setLayoutManager(new LinearLayoutManager(MainActivity.this));
        recyclerView.setHasFixedSize(true);

        adapter = new CustomRecyclerView(MainActivity.this, persons);
        recyclerView.setAdapter(adapter);
        sendRequest();
        */

        list = findViewById(R.id.list);
        arrayList = new ArrayList<>();

        sendRequest();


        sharedpreferences = getSharedPreferences("key_MyPREFERENCES", Context.MODE_PRIVATE);

        FLName = sharedpreferences.getString("key_FLName", "");
        PhoneNumber = sharedpreferences.getString("key_Phone", "");

        tvFLName.setText(FLName);
        tvPhoneNumber.setText(PhoneNumber);
    }

    public void sendRequest() {
        JsonArrayRequest jsonArrayRequest = new JsonArrayRequest(Request.Method.GET, Url, null, new Response.Listener<JSONArray>() {
            @Override
            public void onResponse(JSONArray response) {

                for (int i = 0; i < response.length(); i++) {

                    temp = new Person();

                    try {
                        JSONObject jsonObject = response.getJSONObject(i);

                        temp.setFLName(jsonObject.getString("first_name") + " " + jsonObject.getString("last_name"));
                        temp.setPhoneNumber(jsonObject.getString("phone_number"));
                        temp.setImageUrl(jsonObject.getString("image"));

                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    //persons.add(temp);
                    arrayList.add(temp);
                }
                CustomListAdapter customListAdapter = new CustomListAdapter(MainActivity.this, arrayList);
                list.setAdapter(customListAdapter);
                //adapter.notifyDataSetChanged();


            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                String Error = "error";
                Log.i("Volley Error: ", Error);
            }
        });
        requestQueue.add(jsonArrayRequest);
    }
}