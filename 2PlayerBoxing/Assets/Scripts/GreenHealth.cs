using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GreenHealth : MonoBehaviour 
{
	public float Health = 10;
	public Slider sldr;
	public GameObject LoseScreen;
	
	private void OnTriggerEnter(Collider col)
	{
		if(col.gameObject.tag == "Red")
		{
			Health -=.4f;
			sldr.value = Health;
		}
	}
	
	void Update()
	{
		if(Health <= 0)
	    {
			Time.timeScale = 0;
		    LoseScreen.SetActive(true);
	    }
	}
}
