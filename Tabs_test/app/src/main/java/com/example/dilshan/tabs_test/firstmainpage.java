package com.example.dilshan.tabs_test;

import java.io.IOException;
import java.io.OutputStream;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.UUID;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.UUID;

public class firstmainpage extends AppCompatActivity {

    private static String[] dataArray;
    private static final int REQUEST_ENABLE_BT = 1;
    private static BluetoothAdapter btAdapter = null;
    private static BluetoothSocket btSocket = null;
    private static OutputStream outStream = null;

    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    // private static String address = "00:00:00:00:00:00";

    public void goToManual(View view) {
        Intent i = new Intent(this, MainActivity.class);
        dataArray[1]="MANUAL";
        System.out.println("goToMannual"+Arrays.toString(dataArray));
        startActivity(i);
    }

    public void goToAuto(View view) {
        Intent i = new Intent(this, AutoActivity.class);
        dataArray[1]="AUTO";
        System.out.println("goToAuto"+Arrays.toString(dataArray));
        startActivity(i);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first_page);
        dataArray = new String[]{"ON", "MANUAL", "FIXED", "30", "120", "HIGH", "HIGH", "HIGH", "HIGH"};
        btAdapter = BluetoothAdapter.getDefaultAdapter();
        checkBTState();



    }
    public void changeFanState(View view){
        if (dataArray[0]=="ON"){
            dataArray[0]="OFF";
        }else{
            dataArray[0]="ON";
        }
        sendData();
        Toast.makeText(getBaseContext(),"Fan state changed",Toast.LENGTH_LONG).show();
        System.out.println("changeFn=anState"+Arrays.toString(dataArray));
    }
    private void checkBTState() {
        if (btAdapter == null) {
            errorExit("Fatal Error", "Bluetooth Not supported. Aborting.");
        } else {
            if (btAdapter.isEnabled()) {
            } else {
                // Prompt user to turn on Bluetooth
                Intent enableBtIntent = new Intent(btAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
            }
        }
    }

    private void errorExit(String title, String message) {
        Toast msg = Toast.makeText(getBaseContext(), title + " - " + message, Toast.LENGTH_SHORT);
        msg.show();
        finish();
    }

    public static void sendData() {
        if (btSocket != null) {
            try {
                // Create the command that will be sent to arduino.
                String value = Arrays.toString(dataArray);
                // String must be converted in its bytes to be sent on serial
                // communication
                btSocket.getOutputStream().write(value.getBytes());
            } catch (IOException e) {
            }
        }
    }

    public static String[] getArray(){
        return dataArray;
    }
}
