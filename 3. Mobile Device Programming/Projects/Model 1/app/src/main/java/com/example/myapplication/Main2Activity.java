package com.example.myapplication;

import android.content.Context;
import android.content.SharedPreferences;
import android.support.annotation.NonNull;
import android.support.design.widget.NavigationView;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBar;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Main2Activity extends AppCompatActivity {

    RecyclerView recyclerView;
    RecyclerView.Adapter myAdapter;
    RecyclerView.LayoutManager layoutManager;
    RequestQueue rq;
    List<Contact> contacts;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        Toolbar toolbar = findViewById(R.id.toolbar_activity_main2);
        setSupportActionBar(toolbar);

        ActionBar actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        actionBar.setHomeButtonEnabled(true);

        DrawerLayout drawerLayout = findViewById(R.id.drawerlayout_activity_main2);
        ActionBarDrawerToggle drawerToggle = new ActionBarDrawerToggle(this, drawerLayout, toolbar, 0, 0);
        drawerToggle.syncState();

        NavigationView navigationView = findViewById(R.id.navigationview_activity_main2);
        View v = navigationView.getHeaderView(0);
        TextView sabt_name_activity_main2 = v.findViewById(R.id.sabt_name_activity_main2);
        TextView sabt_shomare_activity_main2 = v.findViewById(R.id.sabt_shomare_activity_main2);

        navigationView.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.nav_item1:
                        Toast.makeText(Main2Activity.this, "nav_item1", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_item2:
                        Toast.makeText(Main2Activity.this, "nav_item2", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_item3:
                        Toast.makeText(Main2Activity.this, "nav_item3", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_item4:
                        Toast.makeText(Main2Activity.this, "nav_item4", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_item5:
                        Toast.makeText(Main2Activity.this, "nav_item5", Toast.LENGTH_SHORT).show();
                        break;
                }
                return true;
            }
        });
        rq = Volley.newRequestQueue(this);
        recyclerView = findViewById(R.id.recycleViewContainer_activity_main2);
        contacts = new ArrayList<>();
        recyclerView.setHasFixedSize(true);
        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        myAdapter = new MyRecyclerAdapter(Main2Activity.this, contacts);
        recyclerView.setAdapter(myAdapter);
        sendRequest();

        final String Preferences_Key = "MyPrefs";
        final String Name_Key = "nameKey";
        final String Shomare_Key = "phoneKey";
        SharedPreferences sharedpreferences = getSharedPreferences(Preferences_Key, Context.MODE_PRIVATE);
        String string1 = sharedpreferences.getString(Name_Key, "");
        String string2 = sharedpreferences.getString(Shomare_Key, "");
        sabt_name_activity_main2.setText(string1);
        sabt_shomare_activity_main2.setText(string2);
    }

    public void sendRequest() {
        final String Link = "http://116.202.20.190:9000/jason/contacts/";
        JsonArrayRequest jsonArrayRequest = new JsonArrayRequest(Request.Method.GET, Link, null, new Response.Listener<JSONArray>() {
            @Override
            public void onResponse(JSONArray response) {
                for (int i = 0; i < response.length(); i++) {
                    Contact temp = new Contact();
                    try {
                        JSONObject jsonObject = response.getJSONObject(i);
                        temp.setName(jsonObject.getString("first_name"));
                        temp.setFamily(jsonObject.getString("last_name"));
                        temp.setShomare(jsonObject.getString("phone_number"));
                        temp.setAddreas(jsonObject.getString("image"));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    contacts.add(temp);
                }
                myAdapter.notifyDataSetChanged();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                String Error = "error";
                Log.i("Volley Error: ", Error);
            }
        });
        rq.add(jsonArrayRequest);
    }
}