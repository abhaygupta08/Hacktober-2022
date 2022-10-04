using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour {

	public Transform Player;
	public Vector3 offset;

	// Use this for initialization
	void Start () 
	{
		offset = transform.position - Player.position;
	}
	
	// Update is called once per frame
	void Update () 
	{
		transform.position = Vector3.Lerp(transform.position, Player.position + offset, 0.1f);
	}
}
