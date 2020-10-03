using System;
using UnityEngine;

// this comes from the Unity Standard Assets
namespace UnityStandardAssets._2D
{
    public class Camera2DFollow : MonoBehaviour
    {
        public Transform target;
        Vector3 offset;

        // Use this for initialization
        private void Start()
        {
            offset = transform.position - target.transform.position;
        }

        // Update is called once per frame
		private void Update()
        {
            transform.position = target.transform.position + offset;
        }
    }
}
