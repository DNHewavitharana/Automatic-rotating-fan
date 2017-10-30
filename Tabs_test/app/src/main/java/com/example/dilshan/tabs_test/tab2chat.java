package com.example.dilshan.tabs_test;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.view.FrameMetrics;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RadioGroup;
import android.widget.TextView;

import com.goodiebag.protractorview.ProtractorView;

/**
 * Created by dilshan on 10/3/17.
 */

public class tab2chat extends Fragment {


    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        final View rootView = inflater.inflate(R.layout.tab2content, container, false);

        ProtractorView protractorView1 = (ProtractorView) rootView.findViewById(R.id.proview1);
        ProtractorView protractorView2 = (ProtractorView) rootView.findViewById(R.id.proview2);
        RadioGroup rg = (RadioGroup) rootView.findViewById(R.id.speedradio2);


        protractorView2.setOnProtractorViewChangeListener(new ProtractorView.OnProtractorViewChangeListener() {
            @Override
            public void onProgressChanged(ProtractorView pv, int progress, boolean b) {
                firstmainpage.getArray()[2]="FIXEDTORANGE";
                TextView startangle = (TextView) rootView.findViewById(R.id.startangle);
                startangle.setText(String.valueOf(progress)+"°");
                firstmainpage.getArray()[3]=String.valueOf(progress);
            }

            @Override
            public void onStartTrackingTouch(ProtractorView pv) {

            }

            @Override
            public void onStopTrackingTouch(ProtractorView pv) {

            }
        });

        protractorView1.setOnProtractorViewChangeListener(new ProtractorView.OnProtractorViewChangeListener() {
            @Override
            public void onProgressChanged(ProtractorView pv, int progress, boolean b) {
                TextView endangle = (TextView) rootView.findViewById(R.id.endangle);
                endangle.setText(String.valueOf(progress)+"°");
                firstmainpage.getArray()[4]=String.valueOf(progress);
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
                TextView speed2 = (TextView) rootView.findViewById(R.id.speed2);
                switch(checkedId) {
                    case R.id.high:
                        speed2.setText("High");
                        firstmainpage.getArray()[5]="HIGH";
                        break;
                    case R.id.medium:
                        speed2.setText("Medium");
                        firstmainpage.getArray()[5]="MEDIUM";
                        break;
                    case R.id.low:
                        speed2.setText("Low");
                        firstmainpage.getArray()[5]="LOW";
                        break;
                    case R.id.off:
                        speed2.setText("Off");
                        firstmainpage.getArray()[5]="OFF";
                        break;
                }
            }
        });

        return rootView;
    }

}
