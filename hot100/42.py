
height = [1,0,2,1,3,1,0,1,2,0,1]

def trap(height):

    sum = 0

    for i, hei in enumerate(height):
        if i == 0 or i == len(height) - 1:
            continue
        
        lhight = height[i]
        rhight = height[i]

        for r, rhi in  enumerate(height[i+1:]):
            if rhi > rhight:
                rhight = rhi

        for l, lhi in enumerate(reversed(height[:i])):
            if lhi > lhight:
                lhight = lhi

        h = min(rhight, lhight) - hei

        if h > 0:
            sum+=h
    
    print(sum)

trap(height)