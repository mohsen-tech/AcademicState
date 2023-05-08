package com.example.myapplication;

import android.content.Context;
import android.content.Intent;
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

public class TempActivity extends AppCompatActivity {

    TextView TextViewUserName, TextViewUserPhoneNumber;

    RecyclerView recyclerView;
    RecyclerView.Adapter mAdapter;
    RecyclerView.LayoutManager layoutManager;

    List<PersonUtils> personUtilsList;

    RequestQueue rq;

    String request_url = "http://116.202.20.190:9000/jason/contacts/";

    public static final String MyPREFERENCES_Key = "MyPrefs";
    public static final String Name_Key = "nameKey";
    public static final String Phone_Key = "phoneKey";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_temp);

        ////////////////////////////////////////
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        ActionBar actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        actionBar.setHomeButtonEnabled(true);

        DrawerLayout drawerLayout = findViewById(R.id.drawerlayout);
        ActionBarDrawerToggle drawerToggle = new ActionBarDrawerToggle(this, drawerLayout, toolbar, 0, 0);
        drawerToggle.syncState();

        NavigationView navigationView = findViewById(R.id.navigation_view);

        View v = navigationView.getHeaderView(0);
        TextViewUserName = v.findViewById(R.id.TextViewUserName);
        TextViewUserPhoneNumber = v.findViewById(R.id.TextViewUserPhoneNumber);

        navigationView.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.nav_about:
                        Toast.makeText(TempActivity.this, "About", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.nav_logout:
                        SharedPreferences sharedpreferences = getSharedPreferences(LogInActivity.MyPREFERENCES_Key, Context.MODE_PRIVATE);
                        SharedPreferences.Editor editor = sharedpreferences.edit();
                        editor.clear();
                        editor.commit();
                        Intent intent = new Intent(TempActivity.this, LogInActivity.class);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                        startActivity(intent);
                        finish();
                        break;
                }
                return true;
            }
        });
        ////////////////////////////////////////

        rq = Volley.newRequestQueue(this);

        recyclerView = findViewById(R.id.recycleViewContainer);


        personUtilsList = new ArrayList<>();

        recyclerView.setHasFixedSize(true);
        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        mAdapter = new CustomRecyclerAdapter(TempActivity.this, personUtilsList);
        recyclerView.setAdapter(mAdapter);

        sendRequest();

        SharedPreferences sharedpreferences = getSharedPreferences(LogInActivity.MyPREFERENCES_Key, Context.MODE_PRIVATE);

        String str1 = sharedpreferences.getString(Name_Key, "");
        String str2 = sharedpreferences.getString(Phone_Key, "");

        TextViewUserName.setText(str1);
        TextViewUserPhoneNumber.setText(str2);
    }

    public void sendRequest() {
        JsonArrayRequest jsonArrayRequest = new JsonArrayRequest(Request.Method.GET, request_url, null, new Response.Listener<JSONArray>() {
            @Override
            public void onResponse(JSONArray response) {

                for (int i = 0; i < response.length(); i++) {

                    PersonUtils personUtils = new PersonUtils();

                    try {
                        JSONObject jsonObject = response.getJSONObject(i);

                        personUtils.setFirstName(jsonObject.getString("first_name"));
                        personUtils.setLastName(jsonObject.getString("last_name"));
                        personUtils.setPhoneNumber(jsonObject.getString("phone_number"));
                        personUtils.setImageLink(jsonObject.getString("image"));

                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    personUtilsList.add(personUtils);
                }
                mAdapter.notifyDataSetChanged();
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

    public void onBackPressed() {
        finishAffinity();
    }
}