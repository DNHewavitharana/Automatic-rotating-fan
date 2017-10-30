package com.example.dilshan.tabs_test;

/**
 * Created by dilshan on 10/3/17.
 */

import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;


import com.goodiebag.protractorview.ProtractorView;


public class tab1contact extends Fragment {
    RadioGroup rg;
    RadioButton rb;


    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        final View rootView = inflater.inflate(R.layout.tab1content, container, false);

        ProtractorView protractorView = (ProtractorView) rootView.findViewById(R.id.proview);
        RadioGroup rg = (RadioGroup) rootView.findViewById(R.id.speedradio);


        protractorView.setOnProtractorViewChangeListener(new ProtractorView.OnProtractorViewChangeListener() {
            @Override
            public void onProgressChanged(ProtractorView pv, int progress, boolean b) {
                firstmainpage.getArray()[2]="FIXED";
                TextView angle = (TextView) rootView.findViewById(R.id.angle);
                angle.setText(String.valueOf(progress)+"°");
                firstmainpage.getArray()[3]=String.valueOf(progress);
            }

            @Override
            public void onStartTrackingTouch(ProtractorView pv) {

            }

            @Override
            public void onStopTrackingTouch(ProtractorView pv) {

            }
        });

        rg.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener()
        {
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                TextView speed = (TextView) rootView.findViewById(R.id.speed);
                switch(checkedId) {
                    case R.id.high:
                        speed.setText("High");
                        firstmainpage.getArray()[5]="HIGH";
                        break;
                    case R.id.medium:
                        speed.setText("Medium");
                        firstmainpage.getArray()[5]="MEDIUM";
                        break;
                    case R.id.low:
                        speed.setText("Low");
                        firstmainpage.getArray()[5]="LOW";
                        break;
                    case R.id.off:
                        speed.setText("Off");
                        firstmainpage.getArray()[5]="OFF";
                        break;
                }
            }
        });
        return rootView;
    }
}
