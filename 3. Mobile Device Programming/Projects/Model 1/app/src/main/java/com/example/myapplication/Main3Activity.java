package com.example.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import de.hdodenhof.circleimageview.CircleImageView;

public class Main3Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        CircleImageView contact_image_activity_main3 = findViewById(R.id.contact_image_activity_main3);
        TextView contact_name_activity_main3 = findViewById(R.id.contact_name_activity_main3);
        TextView contact_shomare_activity_main3 = findViewById(R.id.contact_shomare_activity_main3);
        Bundle extras = getIntent().getExtras();
        final String Address_Key = "MyAddress";
        final String Name_Key = "nameKey";
        final String Shomare_Key = "phoneKey";
        Picasso.with(this)
                .load(extras.getString(Address_Key))
                .resize(200, 200)
                .into(contact_image_activity_main3);
        contact_name_activity_main3.setText(extras.getString(Name_Key));
        contact_shomare_activity_main3.setText(extras.getString(Shomare_Key));
    }
}
