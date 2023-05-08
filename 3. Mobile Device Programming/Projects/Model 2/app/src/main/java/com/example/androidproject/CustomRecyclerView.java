package com.example.androidproject;

import android.content.Context;
import android.content.Intent;

import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.List;

public class CustomRecyclerView extends RecyclerView.Adapter<CustomRecyclerView.ViewHolder> {

    private Context context;
    private List<Person> persons;
    private Person temp;
    private View views;
    Intent intent;

    public CustomRecyclerView(Context context, List person) {
        this.context = context;
        this.persons = person;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.adapter, parent, false);
        ViewHolder viewHolder = new ViewHolder(v);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        holder.itemView.setTag(persons.get(position));

        temp = persons.get(position);

        holder.tvFLName.setText(temp.getFLName());
        holder.tvPhoneNumber.setText(temp.getPhoneNumber());

        Picasso.with(views.getContext())
                .load(temp.getImageUrl())
                .resize(200, 200)
                .into(holder.ivImage);
    }

    @Override
    public int getItemCount() {
        return persons.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        public TextView tvFLName, tvPhoneNumber;
        public ImageView ivImage;

        public ViewHolder(View itemView) {
            super(itemView);

            tvFLName = itemView.findViewById(R.id.tv_fl_name);
            tvPhoneNumber = itemView.findViewById(R.id.tv_phone_number);
            ivImage = itemView.findViewById(R.id.iv_image);
            views = itemView;

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {

                    temp = (Person) view.getTag();

                    intent = new Intent(view.getContext(), PersonInfoActivity.class);
                    intent.putExtra("key_Url", temp.getImageUrl());
                    intent.putExtra("key_FLName", temp.getFLName());
                    intent.putExtra("key_Phone", temp.getPhoneNumber());
                    context = view.getContext();
                    context.startActivity(intent);
                }
            });
        }
    }
}