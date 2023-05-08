package com.example.androidcoder.server;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    //    private RequestQueue mRequestQueue;
//    private StringRequest mStringRequest;
    private String url = "http://www.mocky.io/v2/597c41390f0000d002f4dbd1";
    //    ListView users;
//    private List modelList = new ArrayList();
//    ArrayAdapter<String> arrayAdapter;
    RequestQueue mreqRequestQueue;
    StringRequest stringRequest;
    JsonArrayRequest arrayRequest;
    Button get;
    TextView text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        get = findViewById(R.id.get);
        text = findViewById(R.id.text);

        get.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Get_server();
            }
        });
        //        mreqRequestQueue = Volley.newRequestQueue(this);
//        stringRequest = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
//            @Override
//            public void onResponse(String response) {
//                Toast.makeText(MainActivity.this, response.toString(), Toast.LENGTH_SHORT).show();
//            }
//        }, new Response.ErrorListener() {
//            @Override
//            public void onErrorResponse(VolleyError error) {
//
//            }
//        });
//        mreqRequestQueue.add(stringRequest);

//        mRequestQueue = Volley.newRequestQueue(this);
//
//        mStringRequest = new StringRequest(Request.Method.GET, url,
//                new Response.Listener<String>() {
//                    @Override
//                    public void onResponse(JSONArray response) {
//                        for (int i = 0; i < response.length(); i++) {
//                            try {
//                                JSONObject postArray = response.getJSONObject(i);
//
//                            } catch (JSONException e) {
//                                Log.e("err", "err");
//                            }
//                        }
//                    },new Response.ErrorListener(){
//                        @Override
//                        public void onErrorResponse(VolleyError error){
//                        Log.i("Error :" , error.toString());
//                    }
//                    }
//                });
//
//        {
//            @Override
//            public void onErrorResponse (VolleyError error){
//            Log.i("Get_Error: ", error.toString());
//        }
//        });

//        mRequestQueue.add(mStringRequest);
    }

    private void Get_server() {
        mreqRequestQueue = Volley.newRequestQueue(this);
        arrayRequest = new JsonArrayRequest(Request.Method.GET, url, null, new Response.Listener<ArrayList>() {
            @Override
            public void onResponse(String response) {
//                text.setText(response.toString());
                for (int i = 0; i < response.length(); i++) {
                    JSONObject object = response.get(i);
                    object.getString("id");

                }

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

            }
        });
        mreqRequestQueue.add(stringRequest);
    }

}
