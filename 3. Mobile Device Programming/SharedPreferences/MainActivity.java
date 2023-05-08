package com.example.androidcoder.session1;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    SharedPreferences sharedPreferences;
    Button save , clear;
    EditText name, family;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.sharepref);
        save = findViewById(R.id.save);
        clear = findViewById(R.id.clear);
        name = findViewById(R.id.name);
        family = findViewById(R.id.family);
        sharedPreferences = getSharedPreferences("mypref", Context.MODE_PRIVATE);
        save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String n = name.getText().toString();
                String f = family.getText().toString();
                SharedPreferences.Editor edit = sharedPreferences.edit();
                edit.putString("Name", n);
                edit.putString("Family", f);
                edit.apply();
                Toast.makeText(MainActivity.this, "save success", Toast.LENGTH_SHORT).show();
            }
        });
        clear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SharedPreferences.Editor edit = sharedPreferences.edit();
                edit.clear();
                edit.apply();
                Toast.makeText(MainActivity.this, "clear success", Toast.LENGTH_SHORT).show();
            }
        });
        if (sharedPreferences.contains("Name")) {
            name.setText(sharedPreferences.getString("Name", "name not set"));
        }

        if (sharedPreferences.contains("Family")) {
            family.setText(sharedPreferences.getString("Family", "family not set"));
        }

//                sharedPreferences.getString("Name", n);

    }

}
