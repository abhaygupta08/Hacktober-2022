using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerMovement : MonoBehaviour 
{
	public float speed;
	public Animator anim;
	public float breadth;
	public bool isMoving;
	float InputX = 0.0f;
	float InputY = 0.0f;
	float negativePulseCount = 0;
	AudioSource audioSrc;
	public AudioSource audioSrc2;
	public AudioSource audioSrc3;
	public Slider chaosBar;
	float pulseCarrierCount = 0;
	public GameObject wonScreen;
	
	//time
	public GameObject TimeUp;
	public float timeRemaning=60;
	public bool timeIsrunning;
	public Text timeText;

	void Start()
	{
		Time.timeScale = 1;
		audioSrc = GetComponent<AudioSource>();
	}
	
	// Update is called once per frame
	void Update () 
	{
		if(timeIsrunning=true)
		{
			if(timeRemaning>0)
			{
				timeRemaning-=Time.deltaTime;
				DisplayTime(timeRemaning);
			}
			else
			{
				timeRemaning=0;
				timeIsrunning=false;
		     if(timeRemaning<1)
		      {
				TimeUp.SetActive(true);
				Time.timeScale = 0;
		      }
			}
		}

		if(chaosBar.value == 10)
		{
			wonScreen.SetActive(true);
			Time.timeScale = 0;
			audioSrc.Stop();
		}


		InputX = Input.GetAxis("Horizontal");
		InputY = Input.GetAxis("Vertical");

		

		if(InputX != 0 || InputY !=0)
		{
			anim.SetBool("Walk",true);
			isMoving = true;
		}

		else
		{
			anim.SetBool("Walk",false);
			isMoving = false;
		}

		if(InputX < 0)
		{
			transform.localScale = new Vector3(-breadth,breadth,breadth);
		}

		else if(InputX > 0)
		{
			transform.localScale = new Vector3(breadth,breadth,breadth);
		}
	}

	void FixedUpdate()
	{
		if(isMoving)
		{
			if(!audioSrc.isPlaying)
			{
				audioSrc.Play();
			}
		}
		
		else
		{
			audioSrc.Stop();
		}
		Vector3 movement = new Vector3(InputX*speed,InputY*speed,0);
		transform.Translate(movement);
	}


	private void OnCollisionEnter2D(Collision2D col)
	{
		if(col.gameObject.tag == "negativePulse")
		{
			if(negativePulseCount >= 0 || negativePulseCount <=5)
			{
				negativePulseCount+=1;
			}
			audioSrc2.Play();
		}

		if(col.gameObject.tag == "pulseCarrier")
		{
			audioSrc3.Play();
			if(negativePulseCount > 0)
			{
				pulseCarrierCount += negativePulseCount;
				negativePulseCount = 0;
			}
			
			chaosBar.value = pulseCarrierCount;
		}
	}

	void DisplayTime(float timeTodisplay)
		{
			timeTodisplay+=1;
			float minutes = Mathf.FloorToInt(timeTodisplay/ 60); 
            float seconds = Mathf.FloorToInt(timeTodisplay % 60);
			timeText.text=string.Format("{0:00}:{1:00}", minutes, seconds);
		}
}
