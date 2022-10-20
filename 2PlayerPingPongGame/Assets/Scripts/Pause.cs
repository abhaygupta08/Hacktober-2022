using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pause : MonoBehaviour {

	public GameObject PauseScreen;
	void Update () 
	{
		if(Input.GetKeyDown(KeyCode.Escape))
		{
			PauseScreen.SetActive(true);
			Time.timeScale = 0;
		}	
	}
}
