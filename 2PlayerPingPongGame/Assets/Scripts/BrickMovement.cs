 using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class BrickMovement : MonoBehaviour {

	public float speed,Left = 0,Right = 0;
	bool Apressed = false, Dpressed = false;
	public PauseSettings Ps;
	

	// Use this for initialization

	void Update()
	{
		speed = Ps.Secondsldr.value;
		if(Input.GetKeyDown(KeyCode.A))
		{
			Apressed = true;
			Left = -1;
		}

		else if(Input.GetKeyUp(KeyCode.A))
		{
			Apressed = false;
			Left = 0;
		}

		if(Input.GetKeyDown(KeyCode.D))
		{
			Dpressed = true;
			Right = 1;
		}

		else if(Input.GetKeyUp(KeyCode.D))
		{
			Dpressed = false;
			Right = 0;
		}
	}
	
	void FixedUpdate () 
	{
	
		if(Apressed)
		{
			Vector3 movement = new Vector3(speed*Left,0,0);
			transform.Translate(movement);
		}

		if(Dpressed)
		{
			Vector3 movement = new Vector3(speed*Right,0,0);
			transform.Translate(movement);
		}
	}

	
}
