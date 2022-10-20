using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScoreCheck : MonoBehaviour {

	public BallMovement Bm;
	public SecondBrickMovement SBm;

	public bool GreenWins = false, RedWins = false,Draw = false;

	public GameObject GreenS,RedS,DrawS;

	// Use this for initialization
	void Start () 
	{
		
	}
	
	// Update is called once per frame
	void Update () 
	{
		Display();
	}

	void Display()
	{
		if(GreenWins)
		{
			GreenS.SetActive(true);
		}

		if(RedWins)
		{
			RedS.SetActive(true);
		}

		else if(Draw)
		{
			DrawS.SetActive(true);
		}
	}
}
