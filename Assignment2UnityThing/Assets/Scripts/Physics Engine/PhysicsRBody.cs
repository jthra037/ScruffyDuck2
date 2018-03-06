using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PhysicsRBody : MonoBehaviour
{
    public float mass = 1f;                             // Mass of the RigidBody
    public float bounciness = 1;                        // The bounciness factor (value between 0 and 1, 0 being no bounce, and 1 being super bouncy!)
    public bool obeysGravity = true;                    // Whether or not this body obeys gravity
    public Vector2 gravity = new Vector2(0, -9.8f);     // The gravity vector applied to this body

    public Vector2 currentVelocity;                     // The current velocity the body is moving at
    public Vector2 maxVelocity = new Vector2(10f, 10f); // The maximum allowed velocity for this object

    public bool grounded;

    private Vector2 totalForces;                        
    private PhysicsEngine engine;

    public struct AABB
    {
        public Vector2 bLeft;
        public Vector2 tRight;
    }

    public AABB aabb;


    public void AddForce(Vector2 force)
    {
        totalForces += force;
    }

    public void Stop()
    {
        currentVelocity = Vector2.zero;
        totalForces = Vector2.zero;
    }

    public bool IsGrounded()
    {
        grounded = engine.IsGrounded(this);
        return grounded;
    }

    /*
     * ______________ <-What does this function do?
     * This function sets up the bounding box.
     * It gets the bounds from the renderer and tracks them 
     * for us so the shape seen on the screen is the same shape that
     * is being checked for collisions.
     */
    void SetAABB()
    {
        Bounds bound = new Bounds(new Vector2(0, 0), new Vector2(1, 1));
        Renderer renderer = GetComponent<Renderer>();

        if (renderer)
        {
            bound = renderer.bounds;
        }

        aabb.bLeft = new Vector2(bound.center.x - bound.extents.x, bound.center.y - bound.extents.y);
        aabb.tRight = new Vector2(bound.center.x + bound.extents.x, bound.center.y + bound.extents.y);
    }

    void Start(){
        SetAABB();
        engine = GameObject.FindWithTag("PhysicsEngine").GetComponent<PhysicsEngine>();

        engine.AddRigidBody(this);
    }

    /*
     * ______________ Describe how this function works
     * Determines if the object should be falling or not,
     * then takes into account all the applied forces and
     * translates them into movement of the object.
     */
    public void Integrate(float dT){
        /// 
        /// ______________ What is the purpose of this part of code?
        /// Determine if the object should be falling and applies
        /// gravity if it should to make it fall.
        /// 
        if (obeysGravity && !IsGrounded()){ 
            AddForce(gravity);
        }
        else{
            if (Mathf.Abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
        }
        ///
        ///
        ///

        Vector2 acceleration = totalForces / mass;
        if (mass == 0)
            acceleration = Vector2.zero;
        
        currentVelocity += acceleration * dT;

        if (totalForces.sqrMagnitude < Mathf.Epsilon && currentVelocity.sqrMagnitude < 0.1f)
        {
            currentVelocity = Vector2.zero;
        }

        Vector2 temp = transform.position;
        temp += currentVelocity * dT;
        transform.position = temp;
        SetAABB();


        Debug.Log("Total forces: " + totalForces);

        totalForces = Vector2.zero;
    }
}
