using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Resume : MonoBehaviour {

	public GameObject PauseScreen;
	void Update () 
	{
		if(Input.GetKeyDown(KeyCode.Escape))
		{
			PauseScreen.SetActive(false);
			Time.timeScale = 1;
		}	
	}
}
