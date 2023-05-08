package com.example.androidproject;

import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.squareup.picasso.Picasso;

public class PersonInfoActivity extends AppCompatActivity {

    TextView tvFLName, tvPhoneNumber;
    ImageView ivImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_person_info);

        ivImage = findViewById(R.id.iv_image_info);
        tvFLName = findViewById(R.id.tv_fl_name_info);
        tvPhoneNumber = findViewById(R.id.tv_phone_number_info);

        Bundle extras = getIntent().getExtras();

        Picasso.with(this)
                .load(extras.getString("key_Url"))
                .resize(360, 200)
                .into(ivImage);
        tvFLName.setText(extras.getString("key_FLName"));
        tvPhoneNumber.setText(extras.getString("key_Phone"));
    }
}
