#define DWG_TYPE DWG_TYPE_DIMENSION_ANG2LN
#include "common.c"

void
low_level_process(dwg_object *obj)
{

  // casts dwg object to ang2ln dimension entity
  dwg_ent_dim_ang2ln *dim_ang2ln = dwg_object_to_DIMENSION_ANG2LN(obj);

  // prints horiz dir
  printf("horiz dir of dim_ang2ln : %f\n",
          dim_ang2ln->horiz_dir);

  // prints lspace factor 
  printf("lspace factor of dim_ang2ln : %f\n", 
          dim_ang2ln->lspace_factor);

  // prints lspace style
  printf("lspace style of dim_ang2ln : " FORMAT_BS "\n",
          dim_ang2ln->lspace_style);

  // prints attach point
  printf("attach point of dim_ang2ln : " FORMAT_BS "\n",
          dim_ang2ln->attachment_point);

  // print radius of ang2ln dimension
  printf("Radius of dim_ang2ln : %f\n",
          dim_ang2ln->elevation.ecs_11);

  // prints thickness
  printf("Thickness of dim_ang2ln : %f\n",
          dim_ang2ln->elevation.ecs_12);

  // prints extrusion point
  printf("extrusion of dim_ang2ln : x = %f, y = %f, z = %f\n",
          dim_ang2ln->extrusion.x, dim_ang2ln->extrusion.y,
          dim_ang2ln->extrusion.z);

  // prints insertion scale
  printf("ins_scale of dim_ang2ln : x = %f, y = %f, z = %f\n",
         dim_ang2ln->ins_scale.x, dim_ang2ln->ins_scale.y,
         dim_ang2ln->ins_scale.z);

  // prints 10 point 
  printf("pt10 of dim_ang2ln : x = %f, y = %f, z = %f\n",
          dim_ang2ln->_10_pt.x, dim_ang2ln->_10_pt.y,
          dim_ang2ln->_10_pt.z);

  // prints  13 point
  printf("pt13 of dim_ang2ln : x = %f, y = %f, z = %f\n",
          dim_ang2ln->_13_pt.x, dim_ang2ln->_13_pt.y,
          dim_ang2ln->_13_pt.z);

  // prints 14 point
  printf("pt14 of dim_ang2ln : x = %f, y = %f, z = %f\n",
          dim_ang2ln->_14_pt.x, dim_ang2ln->_14_pt.y,
          dim_ang2ln->_14_pt.z);

  // prints 15 point
  printf("pt15 of dim_ang2ln : x = %f, y = %f, z = %f\n",
          dim_ang2ln->_15_pt.x, dim_ang2ln->_15_pt.y,
          dim_ang2ln->_15_pt.z);

  // print 12 point
  printf("pt12 of dim_ang2ln : x = %f, y = %f\n",
          dim_ang2ln->_12_pt.x, dim_ang2ln->_12_pt.y);

  // print 16 point
  printf("pt16 of dim_ang2ln : x = %f, y = %f\n",
          dim_ang2ln->_16_pt.x, dim_ang2ln->_16_pt.y);

  // prints mid point of text
  printf("text_mid_pt of dim_ang2ln : x = %f, y = %f\n",
          dim_ang2ln->text_midpt.x, dim_ang2ln->text_midpt.y);

  // prints text
  printf("user text of dim_ang2ln : %s\n", dim_ang2ln->user_text);

  // prints text rotation 
  printf("text rotation of dim_ang2ln : %f\n", dim_ang2ln->text_rot);

  // prints insert rotation
  printf("ins rotation of dim_ang2ln : %f\n", dim_ang2ln->ins_rotation);

  // prints arrow1
  printf("arrow1 of dim_ang2ln : " FORMAT_BS "\n", dim_ang2ln->flip_arrow1);

  // prints arrow2
  printf("arrow2 of dim_ang2ln : " FORMAT_BS "\n", dim_ang2ln->flip_arrow2);

  // prints flag2
  printf("flags2 of dim_ang2ln : " FORMAT_BS "\n", dim_ang2ln->flags_1);

  // prints actual measurement
  printf("act_measurement of dim_ang2ln : %f\n",
            dim_ang2ln->act_measurement); 
}

void
api_process(dwg_object *obj)
{
  int error;
  double ecs11, ecs12, act_measure, horiz_dir, lspace_factor, text_rot, 
         ins_rot, ext_line_rot, dim_rot;
  BITCODE_RC flags1, flip_arrow1, flip_arrow2, flags2;
  BITCODE_BS lspace_style, attach_pt;
  char * user_text;
  dwg_point_2d text_mid_pt, pt12, pt16;
  dwg_point_3d pt10, pt13, pt14, pt15, ext, ins_scale;
  dwg_ent_dim_ang2ln *dim_ang2ln = dwg_object_to_DIMENSION_ANG2LN(obj);

  horiz_dir = dwg_ent_dim_ang2ln_get_horiz_dir(dim_ang2ln, &error);
  if ( !error )
      printf("horiz dir of dim_ang2ln : %f\n", horiz_dir);
  else
      printf("error in reading horiz dir \n");

  lspace_factor = dwg_ent_dim_ang2ln_get_elevation_ecs11(dim_ang2ln, 
                  &error);
  if ( !error )
    printf("lspace factor of dim_ang2ln : %f\n", lspace_factor);
  else
    printf("error in reading lspace factor \n");

  lspace_style = dwg_ent_dim_ang2ln_get_elevation_ecs11(dim_ang2ln, 
                  &error);
  if ( !error )
    printf("lspace style of dim_ang2ln : " FORMAT_BS "\n", lspace_style);
  else
    printf("error in reading lspace style \n");

  attach_pt = dwg_ent_dim_ang2ln_get_elevation_ecs11(dim_ang2ln, 
              &error);
  if ( !error )
      printf("attach point of dim_ang2ln : " FORMAT_BS "\n", attach_pt);
  else
      printf("error in reading attach point \n");

  ecs11 = dwg_ent_dim_ang2ln_get_elevation_ecs11(dim_ang2ln, &error);
  if ( !error )
    printf("Radius of dim_ang2ln : %f\n",ecs11);
  else
    printf("error in reading ecs11 \n");

  ecs12 = dwg_ent_dim_ang2ln_get_elevation_ecs12(dim_ang2ln, &error);
  if ( !error )
    printf("Thickness of dim_ang2ln : %f\n",ecs12);
  else
    printf("error in reading ecs12 \n");

  dwg_ent_dim_ang2ln_get_extrusion(dim_ang2ln, &ext, &error);
  if ( !error )
    printf("extrusion of dim_ang2ln : x = %f, y = %f, z = %f\n",
           ext.x, ext.y, ext.z);
  else
    printf("error in reading extrusion \n");

  dwg_ent_dim_ang2ln_get_ins_scale(dim_ang2ln, &ins_scale,
                                   &error);
  if ( !error )
    printf("ins_scale of dim_ang2ln : x = %f, y = %f, z = %f\n",
           ins_scale.x, ins_scale.y, ins_scale.z);
  else
    printf("error in reading ins_scale \n");

  dwg_ent_dim_ang2ln_get_10_pt(dim_ang2ln, &pt10,
                               &error);
  if ( !error )
    printf("pt10 of dim_ang2ln : x = %f, y = %f, z = %f\n",
           pt10.x, pt10.y, pt10.z);
  else
    printf("error in reading pt10 \n");

  dwg_ent_dim_ang2ln_get_13_pt(dim_ang2ln, &pt13,
                               &error);
  if ( !error )
    printf("pt13 of dim_ang2ln : x = %f, y = %f, z = %f\n",
           pt13.x, pt13.y, pt13.z);
  else
    printf("error in reading pt13 \n");

  dwg_ent_dim_ang2ln_get_14_pt(dim_ang2ln, &pt14,
                               &error);
  if ( !error )
    printf("pt14 of dim_ang2ln : x = %f, y = %f, z = %f\n",
           pt14.x, pt14.y, pt14.z);
  else
    printf("error in reading pt14 \n");

  dwg_ent_dim_ang2ln_get_15_pt(dim_ang2ln, &pt15,
                               &error);
  if ( !error )
    printf("pt15 of dim_ang2ln : x = %f, y = %f, z = %f\n",
           pt15.x, pt15.y, pt15.z);
  else
    printf("error in reading pt14 \n");

  dwg_ent_dim_ang2ln_get_12_pt(dim_ang2ln, &pt12,
                               &error);
  if ( !error )
      printf("pt12 of dim_ang2ln : x = %f, y = %f\n",
              pt12.x, pt12.y);
  else
      printf("error in reading pt12 \n");

  dwg_ent_dim_ang2ln_get_16_pt(dim_ang2ln, &pt16,
                               &error);
  if ( !error )
    printf("pt16 of dim_ang2ln : x = %f, y = %f\n",
           pt16.x, pt16.y);
  else
    printf("error in reading pt16 \n");
  
  dwg_ent_dim_ang2ln_get_text_mid_pt(dim_ang2ln, &text_mid_pt,
                                     &error);
  if ( !error )
    printf("text_mid_pt of dim_ang2ln : x = %f, y = %f\n",
           text_mid_pt.x, text_mid_pt.y);
  else
    printf("error in reading text_mid_pt \n");

  user_text = dwg_ent_dim_ang2ln_get_user_text(dim_ang2ln, &error);
  if ( !error )
      printf("user text of dim_ang2ln : %s\n",user_text);
  else
      printf("error in reading user_text \n");

  text_rot = dwg_ent_dim_ang2ln_get_text_rot(dim_ang2ln, &error);
  if ( !error )
      printf(" text rotation of dim_ang2ln : %f\n", text_rot);
  else
      printf("error in reading text rotation \n");

  ins_rot = dwg_ent_dim_ang2ln_get_ins_rotation(dim_ang2ln, &error);
  if ( !error )
      printf("ins rotation of dim_ang2ln : %f\n",ins_rot);
  else
      printf("error in reading ins rotation \n");

  // returns flip arrow 1
  flip_arrow1 = dwg_ent_dim_ang2ln_get_flip_arrow1(dim_ang2ln,
                &error);
  if ( !error )
      printf("arrow1 of dim_ang2ln : " FORMAT_BS "\n",flip_arrow1);
  else
      printf("error in reading arrow1 \n");

  // returns flip arrow 2
  flip_arrow2 = dwg_ent_dim_ang2ln_get_flip_arrow2(dim_ang2ln,
                &error);
  if ( !error ) 
    printf("arrow1 of dim_ang2ln : " FORMAT_BS "\n",flip_arrow2);
  else
    printf("error in reading arrow1 \n");

  // returns flags 1
  flags1 = dwg_ent_dim_ang2ln_get_flags1(dim_ang2ln,
                                         &error);
  if ( !error )
    printf("flags1 of dim_ang2ln : " FORMAT_BS "\n",flags1);
  else
    printf("error in reading flags1 \n");

  act_measure = dwg_ent_dim_ang2ln_get_act_measurement(dim_ang2ln,
                &error);
  if ( !error )
    printf("act_measurement of dim_ang2ln : %f\n",act_measure);
  else
    printf("error in reading act_measurement \n");
}