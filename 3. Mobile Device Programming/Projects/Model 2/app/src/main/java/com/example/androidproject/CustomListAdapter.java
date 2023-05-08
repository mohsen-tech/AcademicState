package com.example.androidproject;

import android.content.Context;
import android.content.Intent;
import android.database.DataSetObserver;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import android.widget.ListAdapter;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;

class CustomListAdapter implements ListAdapter {
    ArrayList<Person> arrayList;
    Context context;

    public CustomListAdapter(Context context, ArrayList<Person> arrayList) {
        this.arrayList = arrayList;
        this.context = context;
    }

    @Override
    public boolean areAllItemsEnabled() {
        return false;
    }

    @Override
    public boolean isEnabled(int position) {
        return true;
    }

    @Override
    public void registerDataSetObserver(DataSetObserver observer) {
    }

    @Override
    public void unregisterDataSetObserver(DataSetObserver observer) {
    }

    @Override
    public int getCount() {
        return arrayList.size();
    }

    @Override
    public Object getItem(int position) {
        return position;
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public boolean hasStableIds() {
        return false;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        final Person subjectData = arrayList.get(position);
        if (convertView == null) {
            LayoutInflater layoutInflater = LayoutInflater.from(context);
            convertView = layoutInflater.inflate(R.layout.adapter, parent, false);
            convertView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {

                    //Person temp = subjectData;

                    Intent intent = new Intent(v.getContext(), PersonInfoActivity.class);
                    intent.putExtra("key_Url", subjectData.getImageUrl());
                    intent.putExtra("key_FLName", subjectData.getFLName());
                    intent.putExtra("key_Phone", subjectData.getPhoneNumber());
                    context = v.getContext();
                    context.startActivity(intent);
                }
            });
            TextView tvFLName = convertView.findViewById(R.id.tv_fl_name);
            TextView tvPhoneNumber = convertView.findViewById(R.id.tv_phone_number);
            ImageView ivImage = convertView.findViewById(R.id.iv_image);


            tvFLName.setText(subjectData.getFLName());
            tvPhoneNumber.setText(subjectData.getPhoneNumber());

            Picasso.with(convertView.getContext())
                    .load(subjectData.getImageUrl())
                    .resize(200, 200)
                    .into(ivImage);
        }
        return convertView;
    }

    @Override
    public int getItemViewType(int position) {
        return position;
    }

    @Override
    public int getViewTypeCount() {
        return arrayList.size();
    }

    @Override
    public boolean isEmpty() {
        return false;
    }
}