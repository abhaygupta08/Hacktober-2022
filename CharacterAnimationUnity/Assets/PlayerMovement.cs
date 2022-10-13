using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour 
{
	public float speed;
	public Animator anim;
	public float breadth;
	public bool isMoving;
	// Use this for initialization
	void Start () 
	{
		
	}
	
	// Update is called once per frame
	void Update () 
	{
		float InputX = Input.GetAxis("Horizontal");
		Vector3 movement = new Vector3(InputX*speed,0,0);
		transform.Translate(movement);

		if(InputX != 0)
		{
			anim.SetTrigger("Walk");
			isMoving = true;
		}

		else
		{
			anim.SetTrigger("Idle");
			isMoving = false;
		}

		if(InputX < 0)
		{
			transform.localScale = new Vector3(breadth,breadth,breadth);
		}

		else if(InputX > 0)
		{
			transform.localScale = new Vector3(-breadth,breadth,breadth);
		}
	}

	public void OnTriggerEnter2D(Collider2D col)
	{
		anim.SetTrigger("Idle");
		if(isMoving)
		{
			anim.SetTrigger("Idle");
		}
		Debug.Log(isMoving);
	}
}
