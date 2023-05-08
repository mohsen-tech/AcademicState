package com.example.androidproject;

public class Person {
    private String FLName;
    private String ImageUrl;
    private String PhoneNumber;

    public String getFLName() {
        return FLName;
    }

    public void setFLName(String flName) {
        this.FLName = flName;
    }

    public String getImageUrl() {
        return ImageUrl;
    }

    public void setImageUrl(String imageUrl) {
        this.ImageUrl = imageUrl;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.PhoneNumber = phoneNumber;
    }
}