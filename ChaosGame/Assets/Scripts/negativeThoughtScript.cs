using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class negativeThoughtScript : MonoBehaviour {
	public List<GameObject> spawnPoints = new List<GameObject>();
	int random;
	public GameObject negitiveThought;

	private void OnCollisionEnter2D(Collision2D col)
	{
		if(col.gameObject.tag == "Player")
		{
			random = Random.Range(0,3);
		
			Instantiate(negitiveThought,spawnPoints[random].transform.position,Quaternion.identity);
		
			Destroy(gameObject);
		}
	}

}
