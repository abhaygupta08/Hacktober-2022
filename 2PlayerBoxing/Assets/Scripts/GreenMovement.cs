using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GreenMovement : MonoBehaviour {

	public Animator Anime;
	public Animator Punch;
	public float MaxSpeed = 1f;
	public Rigidbody rb;
	bool Apressed = false;
	bool Dpressed = false;

	// Use this for initialization
	void Start () 
	{
		Time.timeScale = 1;
		rb = gameObject.GetComponent<Rigidbody>();
	}
	
	// Update is called once per frame
	void Update () 
	{

		if(Input.GetKeyDown(KeyCode.UpArrow))
		{
			Anime.SetTrigger("Play");
			Punch.SetTrigger("Play");
		}

		else if(Input.GetKeyUp(KeyCode.UpArrow))
		{
			Anime.SetTrigger("Stop");
			Punch.SetTrigger("Stop");
		}
	}

	void FixedUpdate()
	{

		if(Input.GetKeyDown(KeyCode.DownArrow))
		{
			Anime.SetTrigger("Crouch");
		}


		if(Input.GetKeyDown(KeyCode.LeftArrow))
		{
			Apressed = true;
		}

		else if(Input.GetKeyUp(KeyCode.LeftArrow))
		{
			Apressed = false;
		}

		if(Apressed)
		{
			rb.AddForce(-10,0,0);
		}

		if(Input.GetKeyDown(KeyCode.RightArrow))
		{
			Dpressed = true;
		}

		else if(Input.GetKeyUp(KeyCode.RightArrow))
		{
			Dpressed = false;
		}

		if(Dpressed)
		{
			rb.AddForce(10,0,0);
			
		}
		rb.velocity = Vector3.ClampMagnitude(rb.velocity,MaxSpeed);
	}
}
