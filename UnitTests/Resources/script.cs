using System;
using System.Runtime.CompilerServices;

class Hello {
    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    extern static string Sample();
}

using System.Runtime.InteropServices;

//[DllImport ("__Internal", EntryPoint="DoSomething")]
//static extern void DoSomething();