#include "mini_rt.h"
#include "include.h"

t_vector get_screen_horizon_vec(t_vector normal)
{
    t_vector ret;
    double mag;

    ret.x = -normal.y;
    ret.y = normal.x;
    ret.z = 0;
    ret = vector_normalize(ret);
    return (ret);
}

t_vector get_screen_vertical_vec(t_vector normal)
{
    t_vector ret;
    double mag;

    ret.x = 0;
    ret.y = -normal.z;
    ret.z = normal.y;
    ret = vector_normalize(ret);
    return (ret);
}

t_vector get_screen_origin(t_world world)
{
    //カメラの中心座標を計算する

    int w_2 = 500 / 2; //world.win_w
    t_vector coor = *world.camera->pos;
    t_vector vec = *world.camera->dir;
    double fov = (double)world.camera->fov;
    t_vector ret;

    printf("camera.coor: %f, %f, %f\n", coor.x, coor.y, coor.z);
    printf("camera->dir: %f, %f, %f\n", vec.x, vec.y, vec.z);
    printf("camera.fov: %f\n", fov);
    printf("tan((double)fov/2): %f\n", tan((double)fov/2));

    ret.x = coor.x + vec.x * (w_2 / tan((double)fov/2));
    ret.y = coor.y + vec.y * (w_2 / tan((double)fov/2));
    ret.z = coor.z + vec.z * (w_2 / tan((double)fov/2));


    printf("ret.vec: %f, %f, %f\n", ret.x, ret.y, ret.z);
    return (ret);

}

t_screen get_screen_start_position(t_world world)
{
    t_vector scr_x;
    t_vector scr_y;
    t_vector ret;
    t_screen screen;

    ret = get_screen_origin(world);
    screen.center = ret;
    scr_x = get_screen_horizon_vec(*world.camera->dir);
    scr_y = get_screen_vertical_vec(*world.camera->dir);
    printf("scr_x.vec: %f, %f, %f\n", scr_x.x, scr_x.y, scr_x.z);
    printf("scr_y.vec: %f, %f, %f\n", scr_y.x, scr_y.y, scr_y.z);
    ret.x += (scr_y.x * 250 - scr_x.x * 250);
    ret.y += (scr_y.y * 250 - scr_x.y * 250);
    ret.z += (scr_y.z * 250 - scr_x.z * 250);
    screen.x = scr_x;
    screen.y = scr_y;
    puts("[get_screen_start_position]");
    printf("ret.vec: %f, %f, %f\n", ret.x, ret.y, ret.z);  
    return (screen);
}
