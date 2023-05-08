package com.example.myapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import de.hdodenhof.circleimageview.CircleImageView;

public class ContactPageActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contact_page);

        CircleImageView circleImageView = findViewById(R.id.profile_image);
        TextView textViewNameFamily = findViewById(R.id.TextViewNameFamily);
        TextView textViewPhoneNumber = findViewById(R.id.TextViewPhoneNumber);

        Bundle extras = getIntent().getExtras();

        Picasso.with(this)
                .load(extras.getString("url"))
                .resize(200, 200)
                .into(circleImageView);
        textViewNameFamily.setText(extras.getString("name_family"));
        textViewPhoneNumber.setText(extras.getString("phone_number"));

    }

    public void back(View view) {
        //Intent intent = new Intent(this, TempActivity.class);
        //intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        //startActivity(intent);
        finish();
    }
}