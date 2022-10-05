using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class PauseSettings : MonoBehaviour {

	public Slider sldr,Secondsldr;
	public BrickMovement Bm;
	public SecondBrickMovement SBm;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Awake() 
	{
		GreenSpeed();
		RedSpeed();
	}

	public void GreenSpeed()
	{
		Bm.speed = Secondsldr.value;
	}

	public void RedSpeed()
	{
	    SBm.speed = sldr.value;
	}
}
