using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class BallMovement : MonoBehaviour {
	
	 
	Rigidbody2D rb;
	static public float Score = 0,SecondScore = 0;
	public AudioSource audiosrc;
	public Text ScoreText,SecondScoreText;
	public GameObject Restarter,RedS,GreenS;
	public AudioSource gameover;

	void Start()
	{
		Restarter.SetActive(false);
		Time.timeScale = 1;
		Vector2 BallForce = new Vector2(0,8);
		rb = GetComponent<Rigidbody2D>();
		Vector3 SpawnPos = new Vector3(Random.Range(3,-3),Random.Range(-0,0),0);
		transform.Translate(SpawnPos);
		rb.AddForce(-BallForce,ForceMode2D.Impulse);
	}

	void Update()
	{
		ScoreText.text = "" + Score;
		SecondScoreText.text = "" + SecondScore;

		if(Score == 15)
		{
			RedS.SetActive(true);
			Score = 0;
			SecondScore = 0;
		}

		if(SecondScore == 15)
		{
			GreenS.SetActive(true);
			Score = 0;
			SecondScore = 0;
		}
	}

	public void OnCollisionEnter2D(Collision2D col)
	{
		int ran = Random.Range(-7,7);
		int force = 15;
		int wallForce = 6;
		int wallSpeed = 6;

		Vector2 WallHit = new Vector2(wallForce,wallSpeed);
		
	    Vector2 BallForce = new Vector2(ran,force);
		if(col.gameObject.tag == "Brick")
		{
			rb.AddForce(-BallForce,ForceMode2D.Impulse);
			audiosrc.Play();
		}

		else if(col.gameObject.tag == "BottomBrick")
		{
			rb.AddForce(BallForce,ForceMode2D.Impulse);
			audiosrc.Play();
		}

		else if(col.gameObject.tag == "RightSideWall")
		{
			rb.AddForce(-WallHit,ForceMode2D.Impulse);
			audiosrc.Play();
		}

		else if(col.gameObject.tag == "LeftSideWall")
		{
			rb.AddForce(WallHit,ForceMode2D.Impulse);
			audiosrc.Play();
		}

		else if(col.gameObject.tag == "Wall")
		{
			
			gameover.Play();
			Time.timeScale = 0;
			StartCoroutine(Restart());
			
		}

		if(col.gameObject.tag == "Goal")
		{
			SecondScore++;
			
		SecondScoreText.text = "" + SecondScore;
		}

		if(col.gameObject.tag == "SecondGoal")
		{
			Score++;
			ScoreText.text = "" + Score;
		}
	}

	private IEnumerator Restart()
	{
		Restarter.SetActive(true);
		yield return new WaitForSeconds(0.6f);
		Time.timeScale = 1;
		
	}

}
