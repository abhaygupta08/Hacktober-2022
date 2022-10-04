using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class thoughtSpawnner : MonoBehaviour {

	public List<GameObject> spawnPoints = new List<GameObject>();
	public GameObject negitiveThought;
	public float delayTime;
	int random;
	public negativeThoughtScript nts;

	void Start()
	{
		Instantiate(negitiveThought,spawnPoints[2].transform.position,Quaternion.identity);
	}

	
}
