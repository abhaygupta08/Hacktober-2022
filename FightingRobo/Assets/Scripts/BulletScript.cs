using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletScript : MonoBehaviour {

	public float waitTime = 1.5f;
	public GameObject BulletBlastPrefab;
	public Transform PosTransform;

	// Use this for initialization
	void Start () 
	{
		StartCoroutine(Destoyer());
	}
	
	// Update is called once per frame
	IEnumerator Destoyer () 
	{
		yield return new WaitForSeconds(waitTime);
		Destroy(gameObject);
	}


	private void OnCollisionEnter2D(Collision2D col)
	{
		BulletBlast();
	}

	void BulletBlast()
	{
		Instantiate(BulletBlastPrefab, PosTransform.position, Quaternion.identity);
		Destroy(gameObject);
	}
}
