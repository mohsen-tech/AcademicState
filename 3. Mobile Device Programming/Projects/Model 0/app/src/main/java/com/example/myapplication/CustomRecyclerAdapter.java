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

public class CustomRecyclerAdapter extends RecyclerView.Adapter<CustomRecyclerAdapter.ViewHolder> {

    private Context context;
    private List<PersonUtils> personUtils;
    View v;

    public CustomRecyclerAdapter(Context context, List personUtils) {
        this.context = context;
        this.personUtils = personUtils;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.single_list_item, parent, false);
        ViewHolder viewHolder = new ViewHolder(v);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        holder.itemView.setTag(personUtils.get(position));

        PersonUtils temp = personUtils.get(position);

        holder.pName.setText(temp.getFirstName() + " " + temp.getLastName());
        holder.pPhoneNumber.setText(temp.getPhoneNumber());

        Picasso.with(v.getContext())
                .load(temp.getImageLink())
                .resize(200, 200)
                .into(holder.profileimage);
    }

    @Override
    public int getItemCount() {
        return personUtils.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        public TextView pName;
        public TextView pPhoneNumber;
        public CircleImageView profileimage;

        public ViewHolder(View itemView) {
            super(itemView);

            pName = itemView.findViewById(R.id.pNametxt);
            pPhoneNumber = itemView.findViewById(R.id.pPhoneNumber);
            profileimage = itemView.findViewById(R.id.profile_image);
            v = itemView;

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {

                    PersonUtils cpu = (PersonUtils) view.getTag();

                    Intent i = new Intent(view.getContext(), ContactPageActivity.class);
                    i.putExtra("url", cpu.getImageLink());
                    i.putExtra("name_family", cpu.getFirstName() + " " + cpu.getLastName());
                    i.putExtra("phone_number", cpu.getPhoneNumber());
                    Context context = view.getContext();
                    context.startActivity(i);
                }
            });
        }
    }
}