package com.example.myapplication;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    EditText name_activity_main, shomare_activity_main;
    Button vorod_activity_main;
    SharedPreferences sharedpreferences;

    public static final String Preferences_Key = "MyPrefs";
    public static final String Name_Key = "nameKey";
    public static final String Shomare_Key = "phoneKey";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        name_activity_main = findViewById(R.id.name_activity_main);
        shomare_activity_main = findViewById(R.id.shomare_activity_main);
        vorod_activity_main = findViewById(R.id.vorod_activity_main);

        sharedpreferences = getSharedPreferences(Preferences_Key, Context.MODE_PRIVATE);

        String str1 = sharedpreferences.getString(Name_Key, "");
        String str2 = sharedpreferences.getString(Shomare_Key, "");

        if (str1.trim().length() > 0 && str2.trim().length() > 0) {
            Intent intent = new Intent(MainActivity.this, Main2Activity.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            startActivity(intent);
            finish();
        } else {
            vorod_activity_main.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {

                    String Name = name_activity_main.getText().toString();
                    String PhoneNumber = shomare_activity_main.getText().toString();

                    if (Name.trim().length() > 0 && PhoneNumber.trim().length() > 0) {

                        SharedPreferences.Editor editor = sharedpreferences.edit();

                        editor.putString(Name_Key, Name);
                        editor.putString(Shomare_Key, PhoneNumber);
                        editor.commit();

                        Intent intent = new Intent(MainActivity.this, Main2Activity.class);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                        startActivity(intent);
                        finish();
                    }
                }
            });
        }
    }
}