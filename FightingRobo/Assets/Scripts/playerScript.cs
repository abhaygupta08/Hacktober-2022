using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerScript : MonoBehaviour 
{

	public float Speed = 0.2f;
	Vector2 Movement;
	private Rigidbody2D rb;

	void Start()
	{
		rb = GetComponent<Rigidbody2D>();
	}
	
	void Update () 
	{
		Movement.x = Input.GetAxis("Horizontal");
		Movement.y = Input.GetAxis("Vertical");
		rb.MovePosition(rb.position + Movement * Speed * Time.fixedDeltaTime);

		Vector3 MousePos = Input.mousePosition - Camera.main.WorldToScreenPoint(transform.position);
		

		float angle = (Mathf.Atan2(MousePos.y,MousePos.x)*Mathf.Rad2Deg) - 90f;
		transform.rotation = Quaternion.AngleAxis(angle,Vector3.forward);

	}
}
