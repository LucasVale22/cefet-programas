package com.intro.android.memoclave;

import android.os.Bundle;
import android.app.Activity;
import android.content.*;
import android.widget.*;
import android.view.*;
//import android.view.Menu;

public class MainActivity extends Activity {
	
	Button button1;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		 
		button1 = (Button)
		findViewById (R.id.button1);
		
		button1.setOnClickListener(new View.OnClickListener() {
			 
			@Override
			public void onClick(View arg0) {
			 
			Intent trocatela = new
			Intent(MainActivity.this,ExProcessing.class);
			MainActivity.this.startActivity(trocatela);
			MainActivity.this.finish();
			 
			}
			});
		 
		
	}

	/*@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}*/

}
