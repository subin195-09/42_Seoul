/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:44:12 by skim              #+#    #+#             */
/*   Updated: 2021/01/28 13:19:29 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_VAR_H
# define CUB_VAR_H

#define mapWidth		24
#define mapHeight		24
#define TILE_SIZE		32
#define screenWidth		(TILE_SIZE * mapWidth)
#define screenHeight	(TILE_SIZE * mapHeight)

#define	map_tile		7
#define map_size		(mapWidth * map_tile)

#define text			11
#define textWidth		64
#define textHeight		64
#define textFloor		3
#define textCeil		6

#define numSprite		19

#define KEY_ESC			53
#define KEY_UP			13
#define KEY_DOWN		1
#define KEY_LEFT		0
#define KEY_RIGHT		2
#define KEY_SP			49

#define X_EVENT_KEY_EXIT		17
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3

#endif
