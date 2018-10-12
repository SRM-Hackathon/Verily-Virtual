using UnityEngine;
using System.Collections;
using System.IO.Ports;


public class Rotator : MonoBehaviour {
    public int rotation;
    public string sensor1;
    public string sensor2;
    public string value;
   
    string x;
    SerialPort serial = new SerialPort("COM5",9600);
	void Update () {

		if (!serial.IsOpen)
						serial.Open ();
        int i = 0;
        /*  value = serial.ReadLine();
          x = serial.ReadLine();

          for(i=0;i<x.Length;i++)
          {
              if (x[i] == 'x')
              {
                  break;
              }
          }*/

        string newVal= null;
               for (i = 0;i<value.Length; i++)
               {    Debug.Log("inloop");
                   newVal = newVal + value[i];
                   if (value[i] == 'x')
                   {
                       sensor1 = value;
                    break;
                   }
                   else if (value[i] == 'y')
                   {
                       sensor2 = value;
                     break;
                   }

               }
      // rotation = int.Parse (serial.ReadLine ());
         
		transform.localEulerAngles = new Vector3(0,rotation,0);

		


	}
}
