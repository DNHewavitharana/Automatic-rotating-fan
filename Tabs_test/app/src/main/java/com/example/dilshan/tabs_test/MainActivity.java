package com.example.dilshan.tabs_test;

import java.io.OutputStream;
import java.util.Arrays;
import java.util.UUID;

import android.content.Intent;
import android.support.design.widget.TabLayout;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

import android.widget.RelativeLayout;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.ArrayAdapter;
import android.widget.Toast;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import com.goodiebag.protractorview.ProtractorView;

import java.io.OutputStream;
import java.util.ArrayList;
import java.util.UUID;


public class MainActivity extends AppCompatActivity {


    private SectionsPagerAdapter mSectionsPagerAdapter;
    //public String[] dataArray;
    private static final int REQUEST_ENABLE_BT = 1;
    private BluetoothAdapter btAdapter = null;
    private BluetoothSocket btSocket = null;
    private OutputStream outStream = null;

    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    // private static String address = "00:00:00:00:00:00";

    /**
     * The {@link ViewPager} that will host the section contents.
     */
    private ViewPager mViewPager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        // Create the adapter that will return a fragment for each of the three
        // primary sections of the activity.
        mSectionsPagerAdapter = new SectionsPagerAdapter(getSupportFragmentManager());

        // Set up the ViewPager with the sections adapter.
        mViewPager = (ViewPager) findViewById(R.id.container);
        mViewPager.setAdapter(mSectionsPagerAdapter);

        TabLayout tabLayout = (TabLayout) findViewById(R.id.tabs);
        tabLayout.setupWithViewPager(mViewPager);
        //dataArray = new String[]{"ON", "NORMAL", "FIXED", "30", "120", "HIGH", "HIGH", "HIGH", "HIGH"};
    }



    public void manualToAuto(View view) {
        Intent i = new Intent(this, AutoActivity.class);
        firstmainpage.getArray()[1]="AUTO";
        startActivity(i);
        System.out.println("manualToAuto"+ Arrays.toString(firstmainpage.getArray()));
    }

    public void setBtn1Clicked(View view){
        firstmainpage.sendData();
        Toast.makeText(getBaseContext(),"Fan state changed",Toast.LENGTH_LONG).show();
        System.out.println("setFan"+ Arrays.toString(firstmainpage.getArray()));
    }
     public void changeFanState(View view){
         if (firstmainpage.getArray()[0]=="ON"){
             firstmainpage.getArray()[0]="OFF";
         }else{
             firstmainpage.getArray()[0]="ON";
         }
         firstmainpage.sendData();
         Toast.makeText(getBaseContext(),"Fan state changed",Toast.LENGTH_LONG).show();
         System.out.println("OnOff"+ Arrays.toString(firstmainpage.getArray()));
     }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }


    public class SectionsPagerAdapter extends FragmentPagerAdapter {

        public SectionsPagerAdapter(FragmentManager fm) {
            super(fm);
        }

        @Override
        public Fragment getItem(int position) {
            switch (position) {
                case 0:
                    tab1contact tab1 = new tab1contact();
                    return tab1;
                case 1:
                    tab2chat tab2 = new tab2chat();
                    return tab2;
                case 2:
                    tab3online tab3= new tab3online();
                    return tab3;
                default:
                    return null;
            }

        }

        @Override
        public int getCount() {
            // Show 3 total pages.
            return 3;
        }

        @Override
        public CharSequence getPageTitle(int position) {
            switch (position) {
                case 0:
                    return "Fixed";
                case 1:
                    return "Fixed to a Range";
                case 2:
                    return "Range Speed Controller";
            }
            return null;
        }
    }
}
