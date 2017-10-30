package com.example.dilshan.tabs_test;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;

public class AutoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_auto);

        Spinner spin1 = (Spinner)findViewById(R.id.spinner);
        Spinner spin2 = (Spinner)findViewById(R.id.spinner2);
        Spinner spin3 = (Spinner)findViewById(R.id.spinner3);
        ArrayList<String> speeds=new ArrayList<>();
        speeds.add("Off");
        speeds.add("Low");
        speeds.add("Medium");
        speeds.add("High");
        ArrayAdapter<String> myadapter = new ArrayAdapter<String>(AutoActivity.this,
                android.R.layout.simple_list_item_1,speeds);

        myadapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        spin1.setAdapter(myadapter);
        spin2.setAdapter(myadapter);
        spin3.setAdapter(myadapter);
    }

    public void autoToManual(View view) {
        Intent i = new Intent(this, MainActivity.class);
        startActivity(i);
    }
    public void changeFanState(View view){
        Toast.makeText(getBaseContext(),"Fan state changed",Toast.LENGTH_LONG).show();
    }
    public void setBtn1Clicked(View view){
        Toast.makeText(getBaseContext(),"Fan state changed",Toast.LENGTH_LONG).show();
    }
}
