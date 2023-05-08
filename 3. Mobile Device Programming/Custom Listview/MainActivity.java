package com.example.androidcoder.listview;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    //    ListView mList;
//    ArrayList<Student> mStudent = new ArrayList<>();
    ListView mList;
    String[] name = new String[]{"abus", "reza", "ali"};
    ArrayList<Student> mStudent = new ArrayList<Student>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));
        mStudent.add(new Student("ali", "yavar"));


        mList = findViewById(R.id.ListView);
        CustomAdapter customAdapter = new CustomAdapter(this, mStudent);
        mList.setAdapter(customAdapter);
        mList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Toast.makeText(MainActivity.this,
                        "index of item:" + position, Toast.LENGTH_SHORT).show();
            }
        });
    }
}
