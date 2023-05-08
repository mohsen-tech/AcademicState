package com.example.myapplication;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class LogInActivity extends AppCompatActivity {

    EditText etName, etPhoneNumber;
    Button btnLogIn;

    public static final String MyPREFERENCES_Key = "MyPrefs";
    public static final String Name_Key = "nameKey";
    public static final String Phone_Key = "phoneKey";

    AlertDialogManager AlertDialog = new AlertDialogManager();

    SharedPreferences sharedpreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        if (!isConnected()) {
            AlertDialog.showAlertDialog(LogInActivity.this, "No Internet Connection!", "Please Check Your Internet Connection");
        }

        etName = findViewById(R.id.EditTextGetName);
        etPhoneNumber = findViewById(R.id.EditTextGetPhoneNumber);
        btnLogIn = findViewById(R.id.BtnLogIn);

        sharedpreferences = getSharedPreferences(MyPREFERENCES_Key, Context.MODE_PRIVATE);

        String str1 = sharedpreferences.getString(Name_Key, "");
        String str2 = sharedpreferences.getString(Phone_Key, "");

        if (str1.length() > 0 && str2.length() > 0) {
            Intent intent = new Intent(LogInActivity.this, TempActivity.class);
            startActivity(intent);
        } else {
            btnLogIn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {

                    String Name = etName.getText().toString();
                    String PhoneNumber = etPhoneNumber.getText().toString();

                    if (Name.trim().length() > 0 && PhoneNumber.trim().length() > 0) {

                        SharedPreferences.Editor editor = sharedpreferences.edit();

                        editor.putString(Name_Key, Name);
                        editor.putString(Phone_Key, PhoneNumber);
                        editor.commit();

                        Intent intent = new Intent(LogInActivity.this, TempActivity.class);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                        startActivity(intent);
                        finish();

                    } else {
                        AlertDialog.showAlertDialog(LogInActivity.this, "LogIn failed...", "Please Enter Name and PhoneNumber");
                    }
                }
            });
        }
    }

    public boolean isConnected() {
        boolean connected = false;
        try {
            ConnectivityManager cm = (ConnectivityManager) getApplicationContext().getSystemService(Context.CONNECTIVITY_SERVICE);
            NetworkInfo nInfo = cm.getActiveNetworkInfo();
            connected = nInfo != null && nInfo.isAvailable() && nInfo.isConnected();
            return connected;
        } catch (Exception e) {
            Log.e("Connectivity Exception", e.getMessage());
        }
        return connected;
    }
}