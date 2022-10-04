using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Health : MonoBehaviour 
{

	public Slider sldr;
	public float health = 5, damage;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void OnCollisionEnter2d(Collision2D col)
	{
		if(col.gameObject.tag == "BUllet")
		{
			health -= damage;
			sldr.value = health;
		}
	}
}
