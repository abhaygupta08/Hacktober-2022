using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletBlastDestroyer : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () 
	{
		StartCoroutine(Destroyer());
	}

	IEnumerator Destroyer()
	{
		yield return new WaitForSeconds(0.2f);
		Destroy(gameObject);
	}
}
