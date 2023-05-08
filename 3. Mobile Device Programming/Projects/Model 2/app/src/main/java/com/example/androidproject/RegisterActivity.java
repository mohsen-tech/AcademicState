package com.example.androidproject;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class RegisterActivity extends AppCompatActivity {

    EditText etFLName, etPhoneNumber;
    Button btnRegister;
    SharedPreferences sharedpreferences;
    String FLName, PhoneNumber;
    Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        etFLName = findViewById(R.id.et_fl_name);
        etPhoneNumber = findViewById(R.id.et_phone_number);
        btnRegister = findViewById(R.id.btn_register);

        sharedpreferences = getSharedPreferences("key_MyPREFERENCES", Context.MODE_PRIVATE);

        FLName = sharedpreferences.getString("key_FLName", "");
        PhoneNumber = sharedpreferences.getString("key_Phone", "");

        if (FLName.length() > 0 && PhoneNumber.length() > 0) {
            intent = new Intent(RegisterActivity.this, MainActivity.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            startActivity(intent);
            finish();
        }
        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                FLName = etFLName.getText().toString();
                PhoneNumber = etPhoneNumber.getText().toString();

                if (FLName.length() > 0 && PhoneNumber.length() > 0) {

                    SharedPreferences.Editor editor = sharedpreferences.edit();

                    editor.putString("key_FLName", FLName);
                    editor.putString("key_Phone", PhoneNumber);
                    editor.commit();

                    intent = new Intent(RegisterActivity.this, MainActivity.class);
                    intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                    startActivity(intent);
                    finish();

                } else {
                    Toast.makeText(RegisterActivity.this, "Please Enter Something!", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}