cpu1: X1
cpu2: X2
cpu3: Y1
cpu4: Idle
A: 0 B: 0 C: 2
waiting queue: Y2 Y3 Z1 Z2 
ending queue: empty!
----------------------------------------------------------------

cpu1: X1
cpu2: X2
cpu3: Y1
cpu4: Idle
A: 0 B: 0 C: 2
waiting queue: Y2 Y3 Z1 Z2 
ending queue: empty!
----------------------------------------------------------------

cpu1: X1
cpu2: X2
cpu3: Y1
cpu4: Y2
A: 1 B: 1 C: 2
waiting queue: Y3 Z1 Z2 
ending queue: X1 Y1 
----------------------------------------------------------------

cpu1: Y3
cpu2: X2
cpu3: Z1
cpu4: Y2
A: 1 B: 1 C: 0
waiting queue: Z2 
ending queue: X1 Y1 X2 
----------------------------------------------------------------

cpu1: Y3
cpu2: Idle
cpu3: Z1
cpu4: Y2
A: 2 B: 1 C: 1
waiting queue: Z2 
ending queue: X1 Y1 X2 Z1 
----------------------------------------------------------------

cpu1: Y3
cpu2: Z2
cpu3: Idle
cpu4: Y2
A: 1 B: 1 C: 0
waiting queue: empty!
ending queue: X1 Y1 X2 Z1 
----------------------------------------------------------------

cpu1: Y3
cpu2: Z2
cpu3: Idle
cpu4: Y2
A: 1 B: 2 C: 1
waiting queue: empty!
ending queue: X1 Y1 X2 Z1 Y2 
----------------------------------------------------------------

cpu1: Y3
cpu2: Z2
cpu3: Idle
cpu4: Idle
A: 1 B: 2 C: 1
waiting queue: empty!
ending queue: X1 Y1 X2 Z1 Y2 
----------------------------------------------------------------

cpu1: Y3
cpu2: Z2
cpu3: Idle
cpu4: Idle
A: 1 B: 2 C: 1
waiting queue: empty!
ending queue: X1 Y1 X2 Z1 Y2 
----------------------------------------------------------------

cpu1: Y3
cpu2: Z2
cpu3: Idle
cpu4: Idle
A: 1 B: 3 C: 2
waiting queue: empty!
ending queue: X1 Y1 X2 Z1 Y2 Y3 
----------------------------------------------------------------

cpu1: Idle
cpu2: Z2
cpu3: Idle
cpu4: Idle
A: 2 B: 3 C: 3
waiting queue: empty!
ending queue: X1 Y1 X2 Z1 Y2 Y3 Z2 
----------------------------------------------------------------

cpu1 Idle-Time: 1
cpu2 Idle-Time: 1
cpu3 Idle-Time: 6
cpu4 Idle-Time: 6