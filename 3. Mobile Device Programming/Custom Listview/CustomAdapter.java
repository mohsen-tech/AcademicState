package com.example.androidcoder.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;


public class CustomAdapter extends BaseAdapter {
    Context mContext;
    ArrayList<Student> mStd;

    public CustomAdapter(Context context, ArrayList<Student> items) {
        this.mContext = context;
        this.mStd = items;
    }


    @Override
    public int getCount() {
        return mStd.size();
    }

    @Override
    public Object getItem(int position) {
        return mStd.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        if (convertView == null) {
            convertView = LayoutInflater.from(mContext).
                    inflate(R.layout.item_row,parent ,false );
        }
        Student item = mStd.get(position);
        TextView nameText = convertView.findViewById(R.id.item_name);
        TextView familyText = convertView.findViewById(R.id.family);

        nameText.setText(item.getName());
        familyText.setText(item.getFamily());


        return convertView;
    }

}
