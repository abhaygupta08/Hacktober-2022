using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooting : MonoBehaviour {

	public GameObject BulletPrefab;
	public Transform FirePoint;
	private bool shoot;
	private bool canShoot = true;
	public float bulletForce;


	void FixedUpdate () 
	{
		if(Input.GetMouseButtonDown(0) && canShoot)
		{
			shoot = true;
			Shoot();
		}

		else if(Input.GetMouseButtonUp(0))
		{
			shoot = false;
		}
	}
	
	void Shoot()
	{
		if(shoot)
		{
			GameObject Bullet = Instantiate(BulletPrefab, FirePoint.position, FirePoint.rotation);
		    Rigidbody2D rb = Bullet.GetComponent<Rigidbody2D>();
		    rb.AddForce(FirePoint.up * bulletForce, ForceMode2D.Impulse);
			StartCoroutine(shootDelay());
		}
	}

	private IEnumerator shootDelay()
	{
		canShoot = false;
		shoot = false;
		yield return new WaitForSeconds(0.2f);
		shoot = true;
		canShoot = true;
	}
}
