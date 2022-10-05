 using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SecondBrickMovement : MonoBehaviour {

	public float speed,Left = 0,Right = 0;
	bool Apressed = false, Dpressed = false;
	public PauseSettings Ps;

	// Use this for initialization


	void Update()
	{
		speed = Ps.sldr.value;
		if(Input.GetKeyDown(KeyCode.LeftArrow))
		{
			Apressed = true;
			Left = -1;
		}

		else if(Input.GetKeyUp(KeyCode.LeftArrow))
		{
			Apressed = false;
			Left = 0;
		}

		if(Input.GetKeyDown(KeyCode.RightArrow))
		{
			Dpressed = true;
			Right = 1;
		}

		else if(Input.GetKeyUp(KeyCode.RightArrow))
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

