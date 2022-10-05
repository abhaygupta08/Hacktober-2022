using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class HomeScreen : MonoBehaviour {

	public GameObject SettingMenu,Buttons;
	public Slider sldr,Secondsldr;
	public BrickMovement Bm;
	public SecondBrickMovement SBm;

	public bool pauseScreen = false,escPressed = false;

	public void StartButton()
	{
		SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex+1);
	}

	public void Settings()
	{
		SettingMenu.SetActive(true);
		Buttons.SetActive(false);
	}

	public void GreenSpeed()
	{
		Bm.speed = Secondsldr.value;
	}

	public void RedSpeed()
	{
	    SBm.speed = sldr.value;
	}

	public void Back()
	{
		SettingMenu.SetActive(false);
		Buttons.SetActive(true);
	}

	
}
