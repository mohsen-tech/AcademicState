package com.example.myapplication;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.List;

import de.hdodenhof.circleimageview.CircleImageView;

public class MyRecyclerAdapter extends RecyclerView.Adapter<MyRecyclerAdapter.ViewHolder> {

    private Context context;
    private List<Contact> contacts;
    View v;

    public MyRecyclerAdapter(Context context, List contact) {
        this.context = context;
        this.contacts = contact;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.adapter_activity_main2, parent, false);
        ViewHolder viewHolder = new ViewHolder(v);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        holder.itemView.setTag(contacts.get(position));

        Contact temp = contacts.get(position);

        holder.contact_name_activity_main2.setText(temp.getName() + " " + temp.getFamily());
        holder.contact_shomare_activity_main2.setText(temp.getShomare());

        Picasso.with(v.getContext())
                .load(temp.getAddreas())
                .resize(100, 100)
                .into(holder.contact_image_activity_main2);
    }

    @Override
    public int getItemCount() {
        return contacts.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        public TextView contact_name_activity_main2;
        public TextView contact_shomare_activity_main2;
        public CircleImageView contact_image_activity_main2;

        public ViewHolder(View itemView) {
            super(itemView);

            contact_name_activity_main2 = itemView.findViewById(R.id.contact_name_activity_main2);
            contact_shomare_activity_main2 = itemView.findViewById(R.id.contact_shomare_activity_main2);
            contact_image_activity_main2 = itemView.findViewById(R.id.contact_image_activity_main2);
            v = itemView;

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Contact temp = (Contact) view.getTag();

                    final String Address_Key = "MyAddress";
                    final String Name_Key = "nameKey";
                    final String Shomare_Key = "phoneKey";

                    Intent i = new Intent(view.getContext(), Main3Activity.class);
                    i.putExtra(Address_Key, temp.getAddreas());
                    i.putExtra(Name_Key, temp.getName() + " " + temp.getFamily());
                    i.putExtra(Shomare_Key, temp.getShomare());
                    Context context = view.getContext();
                    context.startActivity(i);
                }
            });
        }
    }
}