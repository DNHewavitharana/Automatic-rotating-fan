package com.example.dilshan.tabs_test;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import java.util.ArrayList;

/**
 * Created by dilshan on 10/3/17.
 */

public class tab3online extends Fragment {


    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.tab3content, container, false);
        Spinner spin1 = (Spinner)rootView.findViewById(R.id.spinner);
        Spinner spin2 = (Spinner)rootView.findViewById(R.id.spinner2);
        Spinner spin3 = (Spinner)rootView.findViewById(R.id.spinner3);


        ArrayList<String>speeds=new ArrayList<>();
        speeds.add("Off");
        speeds.add("Low");
        speeds.add("Medium");
        speeds.add("High");
        ArrayAdapter<String> myadapter = new ArrayAdapter<String>(getContext(),
                android.R.layout.simple_list_item_1,speeds);

        myadapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        spin1.setAdapter(myadapter);
        spin2.setAdapter(myadapter);
        spin3.setAdapter(myadapter);

        spin1.setOnItemSelectedListener(new Spinner.OnItemSelectedListener(){
            public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {
                firstmainpage.getArray()[2]="RANGECONTROL";
                String selected = parent.getItemAtPosition(pos).toString();
                firstmainpage.getArray()[6]=selected.toUpperCase();
            }

            public void onNothingSelected(AdapterView parent) {
                // Do nothing.
            }
        });
        spin2.setOnItemSelectedListener(new Spinner.OnItemSelectedListener(){
            public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {
                String selected = parent.getItemAtPosition(pos).toString();
                firstmainpage.getArray()[7]=selected.toUpperCase();
            }

            public void onNothingSelected(AdapterView parent) {
                // Do nothing.
            }
        });
        spin3.setOnItemSelectedListener(new Spinner.OnItemSelectedListener(){
            public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {
                String selected = parent.getItemAtPosition(pos).toString();
                firstmainpage.getArray()[8]=selected.toUpperCase();
            }

            public void onNothingSelected(AdapterView parent) {
                // Do nothing.
            }
        });
        return rootView;
    }

}

