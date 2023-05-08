package com.example.androidcoder.listview;


public class Student {
    private String name, family;

    public Student(String name, String family) {
        this.name = name;
        this.family = family;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setFamily(String family) {
        this.family = family;
    }

    public String getName() {
        return name;
    }

    public String getFamily() {
        return family;
    }

}
