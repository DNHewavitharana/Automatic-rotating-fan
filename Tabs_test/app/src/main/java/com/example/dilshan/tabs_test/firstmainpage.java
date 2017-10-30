package com.example.dilshan.tabs_test;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class firstmainpage extends AppCompatActivity {

    public void goToManual(View view) {
        Intent i = new Intent(this, MainActivity.class);
        startActivity(i);
    }

    public void goToAuto(View view) {
        Intent i = new Intent(this, AutoActivity.class);
        startActivity(i);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first_page);
    }
    public void changeFanState(View view){
        Toast.makeText(getBaseContext(),"Fan state changed",Toast.LENGTH_LONG).show();
    }
}
