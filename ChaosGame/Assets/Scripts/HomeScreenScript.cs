using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class HomeScreenScript : MonoBehaviour 
{

	public GameObject buttons;
	public GameObject HTPText;
	public GameObject LevelB;
	public GameObject HomeB;

	// Use this for initialization
	public void Startbutton () 
	{
		SceneManager.LoadScene("firstScene");	
	}

	public void HTPbutton()
	{
		buttons.SetActive(false);
		HTPText.SetActive(true);
	}

	public void Quit()
	{
		Application.Quit();
	}

	public void Back()
	{
		buttons.SetActive(true);
		HTPText.SetActive(false);
	}
}
